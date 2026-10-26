#include "f1c/logging/logger.hpp"

#include <chrono>
#include <iomanip>
#include <stdexcept>

namespace f1c::logging {

Logger::Logger(const std::filesystem::path& path)
    : stream_(path, std::ios::out | std::ios::app) {
    if (!stream_) {
        throw std::runtime_error("unable to open log file: " + path.string());
    }
}

void Logger::info(std::string_view message) {
    write("INFO", message);
}

void Logger::error(std::string_view message) {
    write("ERROR", message);
}

void Logger::write(std::string_view level, std::string_view message) {
    const auto now = std::chrono::system_clock::now();
    const auto time = std::chrono::system_clock::to_time_t(now);
    std::tm local{};
#ifdef _WIN32
    localtime_s(&local, &time);
#else
    localtime_r(&time, &local);
#endif
    std::lock_guard lock(mutex_);
    stream_ << std::put_time(&local, "%Y-%m-%d %H:%M:%S")
            << " [" << level << "] " << message << '\n';
    stream_.flush();
}

}  // namespace f1c::logging
