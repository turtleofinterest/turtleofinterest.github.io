# Contributing to VGMTrans
## Licensing 
By making any contributions to VGMTrans you agree that any code you have contributed shall be licensed under the zlib/libpng license.

## General notes
The codebase currently being converted to follow `C++14` (and in the future, `C++17`). We support any `C++14`-compliant compiler, so be sure to test your changes across as many as possible (Travis is supposed to help with this). Keep your code portable and always prefer builtins over macros. Don't use global namespaces. Use raw pointers only when strictly necessary (smart pointers are always preferred over manual memory management). Range-based for-loops are preferred over iterators.

When making UI changes, please include a screenshot.

This tool deals with proprietary formats, so keep your code well documented and *never* include copyrighted data directly (decryption keys and anything of the sort).

## Formatting*
Our code formatting guidelines are similar to [Google's](https://google.github.io/styleguide/cppguide.html), but with a few different aspects.
Be sure to run clang-format before committing.

**Please note that this is not yet applied to all the files, but it shall be.*

### Naming
  - Use uppercase for compile-time constants (e.g. `constexpr int HAX = 1337;`)
  - *Never* use Hungarian notation (e.g `bool bItemChecked;`)
  - Separate words in variable names using underscores (e.g. `double your_fancy_number;`)
  - Class variables should end with an underscore
  - Everything else should be camel case

### Classes and data
  - The class layout should be: `public, protected, private`
  - Use structs for plain-old-data types
  - Avoid non-portable data types
