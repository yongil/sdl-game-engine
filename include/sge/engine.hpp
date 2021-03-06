#ifndef __SGE_ENGINE_HPP
#define __SGE_ENGINE_HPP

#include <sge/config.hpp>

#include <sge/init.hpp>
#include <sge/initializers/sdl.hpp>
#include <sge/initializers/sdl-image.hpp>
#include <sge/initializers/sdl-mixer.hpp>
#include <sge/initializers/sdl-fonts.hpp>
#include <sge/initializers/sdl-window.hpp>

#include <sge/renderer.hpp>
#include <sge/mainloop.hpp>
#include <sge/actionmgr.hpp>
#include <sge/audiomgr.hpp>
#include <sge/scenemgr.hpp>
#include <sge/nodemgr.hpp>
#include <sge/physics/manager.hpp>

#include <sge/assets/manager.hpp>
#include <sge/assets/locators/file.hpp>
#include <sge/assets/loaders/image.hpp>
#include <sge/assets/loaders/audio.hpp>
#include <sge/assets/loaders/font.hpp>
#include <sge/assets/loaders/json.hpp>

#include <memory>

namespace sge
{
    class Engine
    {
        public:
            Engine(Configuration &configuration);
            ~Engine();

            void init();

            Configuration &configuration();
            Startup &startup();
            MainLoop &mainloop();
            ActionManager &actions();
            AudioManager &audio();
            AssetManager &assets();
            SceneManager &scenes();
            NodeManager &nodes();
            PhysicManager &physics();

            SDL_Window *window() const;
            Renderer &renderer();

        private:
            Configuration _configuration;

            Startup _startup;
            std::shared_ptr<SDLInitializer> _sdl_init;
            std::shared_ptr<SDLImageInitializer> _sdl_img_init;
            std::shared_ptr<SDLMixerInitializer> _sdl_mixer_init;
            std::shared_ptr<SDLFontsInitializer> _sdl_fonts_init;
            std::shared_ptr<SDLWindowInitializer> _sdl_window_init;

            Renderer _renderer;
            MainLoop _mloop;
            ActionManager _amgr;
            AudioManager _audiomgr;
            SceneManager _scmgr;
            NodeManager _nodemgr;
            PhysicManager _pmgr;

            AssetManager _assets;

            std::shared_ptr<FileLocator> _asset_file_locator;
            std::shared_ptr<ImageLoader> _asset_image_loader;
            std::shared_ptr<AudioLoader> _asset_audio_loader;
            std::shared_ptr<FontLoader> _asset_font_loader;
            std::shared_ptr<JSONLoader> _asset_json_loader;
    };
}

#endif /* __SGE_ENGINE_HPP */
