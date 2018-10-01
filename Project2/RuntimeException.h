/* RuntimeException.h
 * generic run-time exception class
 * from Goodrich, Tamassia and Mount, Data Structures and Algorithms in C++
 * Code Fragment in section 2.4
 */

#include <string>
using std::string;

class RuntimeException {
private:
  string errorMsg;
public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const { return errorMsg; }
};

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e)
  { return out << e.getMessage(); }
