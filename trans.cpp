#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream inputFile("../site/index.html");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    std::regex pattern1(R"(<div class="md-sidebar md-sidebar--secondary")");
    std::string replacement1 = R"($& id="index-toc")";
    std::string replacedContent = std::regex_replace(content, pattern1, replacement1);
    std::regex pattern2(R"(<div class=md-sidebar__scrollwrap>)");
    std::string replacement2 = R"(<div itemscope="" itemtype="http://schema.org/Person" class="profile_box" style="padding-left: 1.3rem;padding-right: 1.1rem;"><div class="author__avatar"><img src="https://coderbak.com/document/avatar.jpeg" class="author__avatar"></div>
  <div class="author__content">
    <hr><h3 class="author__name" style="font-size: .9rem !important;">Haoxiang Sun</h3>
    <p class="author__bio">Renmin University of China</p>
  </div>
  <div class="author__urls-wrapper">
    <!-- <button class="btn btn--inverse">More Info & Contact</button> -->
    <ul class="author__urls social-icons" style="">
        <li><div style="white-space: normal; margin-bottom: 1em;">This part is self introduction for test. Website under construction.
        </div></li>
    </ul>
  </div>
</div>
    <div class=md-sidebar__scrollwrap style="display: none !important;">)";
    std::string replacedContent2 = std::regex_replace(replacedContent, pattern2, replacement2);
    inputFile.close();
    std::ofstream outputFile("../site/index.html");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }
    outputFile << replacedContent2;
    outputFile.close();
    std::cout << "Replacement completed successfully." << std::endl;
    return 0;
}
