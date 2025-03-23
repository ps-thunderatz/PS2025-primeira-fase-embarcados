/**
 * @file utils.hpp
 *
 * @brief Utility functions
 */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils {
/**
 * @brief Map a value from one range to another
 *
 * @param value Value to map
 * @param from_low Lower bound of the original range
 * @param from_high Upper bound of the original range
 * @param to_low Lower bound of the new range
 * @param to_high Upper bound of the new range
 *
 * @return Mapped value
 */
constexpr float map(float value, float from_low, float from_high, float to_low, float to_high) {
    return (value - from_low) * (to_high - to_low) / (from_high - from_low) + to_low;
}

/**
 * @brief Clamp a value to a range
 *
 * @param value Value to clamp
 * @param low Lower bound of the range
 * @param high Upper bound of the range
 *
 * @return Clamped value
 */
constexpr float clamp(float value, float low, float high) {
    return value < low ? low : (value > high ? high : value);
}

/**
 * @brief Calculate the absolute value of a number
 *
 * @param value Value to calculate the absolute value of
 *
 * @return Absolute value of the number
 */
constexpr float abs(float value) {
    return value < 0 ? -value : value;
}

}  // namespace utils

#endif  // UTILS_HPP
