#ifndef __SGE_ACTION_MANAGER_HPP
#define __SGE_ACTION_MANAGER_HPP

#include <SDL.h>

#include <unordered_map>
#include <string>
#include <list>

namespace sge
{
    class SGEActionManager
    {
        public:
            void register_keyboard_action(std::string const &name, SDL_Keycode key);
            void register_mouse_action(std::string const &name, Uint8 button);
            void register_joystick_action(std::string const &name, Uint8 button);

            bool is_action_pressed(std::string const &name) const;
            bool is_action_released(std::string const &name) const;

            bool event_handler(SDL_Event *event);

        private:
            std::unordered_map<std::string, std::list<SDL_Keycode>> a_keyboard;
            std::unordered_map<std::string, std::list<Uint8>> a_mouse;
            std::unordered_map<std::string, std::list<Uint8>> a_joystick;

            std::unordered_map<std::string, bool> a_active;
    };
}

#endif /* __SGE_ACTION_MANAGER_HPP */