#include "format.hpp"

namespace Logging {
    // constructor
    Format::Format(string_view view)
        : m_View(view) {}
    // close
    string Format::close() {
        m_Stream << m_View;
        m_View = string_view();
        return m_Stream.str();
    }
}