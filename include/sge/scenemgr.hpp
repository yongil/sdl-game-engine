#ifndef __SGE_SCENE_MANAGER_HPP
#define __SGE_SCENE_MANAGER_HPP

#include <sge/engine-forward.hpp>
#include <sge/mainloop.hpp>
#include <sge/node.hpp>

#include <unordered_map>
#include <string>

namespace sge
{
    class SGEScene
    {
        public:
            SGEScene();
            ~SGEScene();

            virtual void load(SGEngine *engine) = 0;
            virtual void unload(SGEngine *engine) = 0;

            SGENode *get_root_node() const;

        private:
            SGENode *root_node;
    };

    class SGESceneManager
    {
        public:
            SGESceneManager(SGEngine *engine);
            ~SGESceneManager();

            void add_scene(std::string const &name, SGEScene *scene);
            void switch_to_scene(std::string const &name);

            bool event_handler(SGEMainLoop *mainloop, SDL_Event *event, void *unused);
            void process_handler(SGEMainLoop *mainloop, Uint32 delta, void *unused);
            void draw_handler(SGEMainLoop *mainloop, void *unused);

        private:
            SGEngine *engine;
            SGEScene *current_scene;

            std::unordered_map<std::string, SGEScene *> scenes;
    };
}

#endif /* __SGE_SCENE_MANAGER_HPP */
