#ifndef LOG_H_
#define LOG_H_

#include <memory>

#include "spdlog/spdlog.h"

namespace Axel {
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& CoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& ClientLogger() { return s_ClientLogger; }
    
    private:
        // Used in the engine.
        static std::shared_ptr<spdlog::logger> s_CoreLogger;

        // Used in the client application code.
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define AX_CORE_TRACE(...)   ::Axel::Log::CoreLogger()->trace(__VA_ARGS__)
#define AX_CORE_INFO(...)    ::Axel::Log::CoreLogger()->info(__VA_ARGS__)
#define AX_CORE_WARN(...)    ::Axel::Log::CoreLogger()->warn(__VA_ARGS__)
#define AX_CORE_ERROR(...)   ::Axel::Log::CoreLogger()->error(__VA_ARGS__)
#define AX_CORE_FATAL(...)   ::Axel::Log::CoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AX_TRACE(...)        ::Axel::Log::ClientLogger()->trace(__VA_ARGS__)
#define AX_INFO(...)         ::Axel::Log::ClientLogger()->info(__VA_ARGS__)
#define AX_WARN(...)         ::Axel::Log::ClientLogger()->warn(__VA_ARGS__)
#define AX_ERROR(...)        ::Axel::Log::ClientLogger()->error(__VA_ARGS__)
#define AX_FATAL(...)        ::Axel::Log::ClientLogger()->fatal(__VA_ARGS__)

#endif // LOG_H_