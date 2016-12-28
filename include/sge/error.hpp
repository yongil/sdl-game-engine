#ifndef __SGE_EXCEPTION_HPP
#define __SGE_EXCEPTION_HPP

#include <exception>
#include <string>

namespace sge
{
    class SGEException : public std::exception
    {
        public:
            SGEException(std::string const &domain, std::string const &msg) throw() : domain(domain), msg(msg) {}
            virtual ~SGEException() throw() {}

            virtual const char *what() const throw()
            {
                std::string result ("[" + domain + "] " + msg);
                return result.c_str();
            }

        private:
            std::string domain;
            std::string msg;
    };
}

#endif /* __SGE_EXCEPTION_HPP */