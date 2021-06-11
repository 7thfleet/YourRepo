# CMake Example
This is a small project intended to serve as an example/template for CMake projects. It contains about 100 lines of CMake. Read below for instructions on how to use this template for your own project.

# How to use this example for your own project.
This example project is a short application. If you want to use this project as a base for a library only project (no executable), you will have to do more in-depth modifications. I have omitted them to keep this guide short.


1. Create a new repository on GitHub. In the steps that follow, replace any occurance of `YourRepo` with your repository name. Replace any occurance of `RepoOwner` with the repository's owner. For example, for this repository, `YourRepo` is `CMake_Example`, and `RepoOwner`, is `7thfleet`. It is also assumed that `YourRepo` is the desired name of the project.
2. Clone this repository, rename it, and `cd` into it:
```bash
git clone https://github.com/7thfleet/CMake_Example.git
mv CMake_Example YourRepo
cd YourRepo
```
3. Delete the `LICENSE` file, and remove all references to CC0:
```fish
rm LICENSE
sed 's/CC0/@@TODO/g' README_TEMPLATE.md -i
sed 's/public-domain//g' README_TEMPLATE.md -i
```
4. Rename the README template:
```
mv README_TEMPLATE.md README.md
```
5. Update `CMakeLists.txt` files and a few cpp files, replacing `MathUtils` with `YourRepo`
```
find . -type f -name "CMakeLists.txt" -exec sed -i 's/MathUtils/YourRepo/g' {} \;
find . -type f -name "*.*pp" -exec sed -i 's/MathUtils/YourRepo/g' {} \;
```
6. Rename some folders and files to match the updated `CMakeLists.txt` files:
```
mv include/MathUtils include/YourRepo
mv src/MathUtils src/YourRepo
mv tests/MathUtils/MathUtils.test.cpp tests/MathUtils/YourRepo.test.cpp
mv tests/MathUtils tests/YourRepo
mv tests/MathUtils-bin tests/YourRepo-bin
```
7. At this point you should be able to generate and build the project successfully:
```
cmake -B build
cmake --build build
```
8. Remove the old origin, and point it at your new repository:
```
git remote remove origin
git remote add origin https://github.com/RepoOwner/YourRepo.git
git branch -M main
git add .
git commit -m "Init"
git push -u origin main
```

9. Navigate to the repository on GitHub, and verify that the CI begins after a few minutes.

10. Go through the README.md and fill revise it to fit your application. Add a LICENSE. I have marked certain places that you should look at with `@@TODO`. You can find them by running this command: `grep -rn "@@TODO"`.

You should now be good to go!

# Adding External Libraries
If the library uses CMake, and uses it properly, you can use FetchContent, as shown in this example with the fmt and doctest library. If the library doesn't support CMake, the easiest way is to use or write a find module.

# Things this example does **not** do
* Allow for the project to be used as a dependency(i.e. dedicated library project). About half the work is done, the other half was omitted to keep the size small.
* Allow for proper system-wide installation using CMake. As with the previous point, this was omitted to keep the project short.
* Build Doxygen documentation
* Build hosted documentation
* Provide support for things like AddressSanitizer, ThreadSanitizer, MemorySanitizer, etc

# Resources used
* https://github.com/vector-of-bool/pitchfork
* https://cliutils.gitlab.io/modern-cmake/
* https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
* https://lefticus.gitbooks.io/cpp-best-practices/content/

# Misc Notes
* The default configuration has a fair amount of warnings enabled by default. You may wish to turn some off if you find them excessive.
* You might consider enabling -Werror for the CI.
* For a larger project, consider adding CI features like code coverage checking, input fuzzing, etc.
* This project has both regular unit tests, and a CMake test that directly invokes the executable and checks its output. If you don't want this, look in the file tests/CMakeLists.txt for instructions.

# Libraries Used
* [doctest](https://github.com/onqtam/doctest/) is the testing library used here. It is similar to `catch2`, but compiles much faster.
* [{fmt}](https://github.com/fmtlib/fmt) is a formatting library that is safer and better than C-style printf or C++ style << chevron << hell << . It is the basis for C++20's `std::format`, if that gives it some credibility. Highly recommended.

# Recommended Libraries
You might find these libraries useful, depending on your application.
* [spdlog](https://github.com/gabime/spdlog) is a good logging library
* [(Boost) Asio](https://think-async.com/Asio/) is a good networking library. Note it is standalone: you don't need all of Boost to use it.
* [pybind11](https://github.com/pybind/pybind11) looks like a better solution than SWIG for C++ <--> Python bindings.
* [nlohmann::json](https://github.com/nlohmann/json) is a very good but hard to spell JSON library.
* [cereal](http://uscilab.github.io/cereal/) is a clean serialization library.
* For option parsing, maybe try [cxxopts](https://github.com/jarro2783/cxxopts). I haven't used it before, but hand-rolling your own with `getopt` sucks.
* For other things, consider browsing [this list](https://en.cppreference.com/w/cpp/links/libs), and checking what people on the [cpp subreddit](reddit.com/r/cpp) think.

# License
The **code** for this repository and `CoolLogo.png` is CC0/public domain(The libraries used are only fetched during build times. This means the binaries are (probably, I'm not a lawyer) not CC0. Since this is an example project, and no binaries are being distributed, it doesn't matter. CC0/public domain means this code this completely free, you can do anything you want with it. If you would like this code released under a different license (like BSD0 for example), please open an issue.

tl;dr you should be able to do whatever you want with this code with no restrictions.

# Author
This example project was developed by Jared White.
[LinkedIn](https://www.linkedin.com/in/jared7white/)
[GitHub](https://www.github.com/7thfleet)
