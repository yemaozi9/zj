#pragma once
#include <cstdint> //��׼��������ͷ�ļ�
#include <stdexcept>
#include <spdlog/spdlog.h>

namespace zj
{
    class LogSystem final
    {
    public:
        enum class logLevel :uint8_t
        {
            debug,
            info,
            warn,
            error,
            fatal
        };

    public:
        LogSystem();
        ~LogSystem();

        template<class...TARGS>
        void log(logLevel level, TARGS&&... args)
        {
            switch (level)
            {
            case LogLevel::debug:
                m_logger->debug(std::forward<TARGS>(args)...);
                break;
            case LogLevel::info:
                m_logger->info(std::forward<TARGS>(args)...);
                break;
            case LogLevel::warn:
                m_logger->warn(std::forward<TARGS>(args)...);
                break;
            case LogLevel::error:
                m_logger->error(std::forward<TARGS>(args)...);
                break;
            case LogLevel::fatal:
                m_logger->critical(std::forward<TARGS>(args)...);
                fatalCallback(std::forward<TARGS>(args)...);
                break;
            default:
                break;
            }
        }
        template<class...TARGS>
        void fatalCallback(TARGS&&...args)
        {
            const std::string format_str = fmt::format(std::forward<TARGS>(args)...);
            throw std::runtime_error(format_str):
        }
    private:
        std::shared_ptr<spdlog::logger> m_logger;
    };




}