#include "Exception.hpp"

namespace Pals {
        namespace Utils {

                Exception::Exception() {

                }

                Exception::~Exception() throw() {

                }

                const char *Exception::what() const throw() {
                        return "";
                }
        }
}
