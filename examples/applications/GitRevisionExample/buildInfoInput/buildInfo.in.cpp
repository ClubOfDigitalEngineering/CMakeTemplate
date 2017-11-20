

namespace buildinfo
{
    const char *gitCommitHash() { return "@git_commit_hash@";  }
    const char *gitBranch()     { return "@git_branch@";       }
    const char *buildType()     { return "@CMAKE_BUILD_TYPE@"; }
    const char *compilerFlags() { return "@COMPILER_FLAGS@";   }
    const char *buildMachine()  { return "@computerName@";     }
    const char *projectDir()    { return "@CMAKE_SOURCE_DIR@"; }
    const char *binaryDir()     { return "@CMAKE_BINARY_DIR@"; }
}
