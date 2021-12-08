#include <iostream>
#include <fstream>
#include<algorithm>
#include<string>
#include <cstring>


//  int main()
//  {
//    std::ifstream data_file("/proc/uptime");
//    double system_uptime;
//    while(data_file.good())
//    {
//      std::string line;
//       while(std::getline(data_file, line))
//        {
//         std::cout<<line<<std::endl;
//         double end_of_uptime= line.find(" ");
//         std::string uptime_string = line.substr(0, line.find(" "));
//         std::cout<<uptime_string<<std::endl;
        
//         char* uptime_string_char = new char[uptime_string.length()+1];
//         std::strcpy (uptime_string_char, uptime_string.c_str());
//         system_uptime = atof(uptime_string_char);
//       }
//    }

//    return system_uptime;
//  }

// int main()
// {
//   std::ifstream data_file("/proc/stat");
//   double running_process;
//   while(data_file.good())
//   {
//     std::string line;
//     while(std::getline(data_file, line))
//      {
//        if(line.find("procs_running") == 0)
//        {
//          std::string running_process_String = line.substr(line.find(" ") + 1, line.length() - line.find(" "));
//          char* run_process_string = new char[process_String.length()+1];
//          std::strcpy (run_process_string, running_process_String.c_str());
//          running_process = atof(run_process_string); 
//        }
//      }
//   }
  
//   return running_process;
// }


// int main()
// {
//   std::ifstream data_file("/proc/stat");
//   double total_process;
//   while(data_file.good())
//   {
//     std::string line;
//      while(std::getline(data_file, line))
//      {
//        if(line.find("processes") == 0)
//        {
//          std::string process_String = line.substr(line.find(" ") + 1, line.length() - line.find(" "));
//          char* tot_process_string = new char[process_String.length()+1];
//          std::strcpy (tot_process_string, process_String.c_str());
//          total_process = atof(tot_process_string); 
//        }
//      }
//   }
  
//   return total_process;
// }

// int main()
// {
  
//   std::ifstream version_file("/proc/meminfo");
//   float totalMemory = 0, freeMemory = 0;
//   while(version_file.good())
//   {
//     std::string line;
//     while(std::getline(version_file, line))
//     {
//       if(line.find("MemTotal") == 0 || line.find("MemFree") == 0)
//       {
//         int colon_quote = line.find(":");
//         int kb_quote = line.find("kB");
//         std::string memString = line.substr(colon_quote + 1,kb_quote - colon_quote - 1);
//         memString.erase(remove_if(memString.begin(), memString.end(), isspace), memString.end());
        
//         char * cstr = new char [memString.length()+1];
//         std::strcpy (cstr, memString.c_str());
        
//         std::cout<<cstr<<std::endl;
//         if(totalMemory < 1.0)
//           totalMemory = atof(cstr);
//         else
//           freeMemory = atof(cstr);
//       }
//     }
//   }
//   std::cout<<((totalMemory - freeMemory)/totalMemory) * 100.0<<std::endl;  
// }

// int main()
// {
//   std::ifstream version_file("/proc/meminfo");
//   while(version_file.good())
//   {
//     std::string line;
//     int totalMemory = 0, freeMemory = 0;
//     std::string::size_type sz; 
//     while(std::getline(version_file, line))
//     {
//       if(line.find("MemTotal") == 0)
//       {
//         int colon_quote = line.find(":");
//         int kb_quote = line.find("kB");
//         std::string memTotal = line.substr(colon_quote + 1,kb_quote - colon_quote - 1);
//         memTotal.erase(remove_if(memTotal.begin(), memTotal.end(), isspace), memTotal.end());
        
//         char * cstr = new char [memTotal.length()+1];
//         std::strcpy (cstr, memTotal.c_str());
        
//         totalMemory = atoi(cstr);
//         std::cout<<totalMemory<<std::endl;
//       }
        
//       if(line.find("MemFree") == 0)
//       {
//         int colon_quote = line.find(":");
//         int kb_quote = line.find("kB");
//         std::string memFree = line.substr(colon_quote + 1,kb_quote - colon_quote - 1);
//         memFree.erase(remove_if(memFree.begin(), memFree.end(), isspace), memFree.end());
        
//         char * cstr = new char [memFree.length()+1];
//         std::strcpy (cstr, memFree.c_str());
        
//         freeMemory = atoi(cstr);
//         std::cout<<freeMemory<<std::endl;
        
//       }
//     }
//   }

//   return 0;
// }

// int main()
// {
//   std::ifstream version_file("/proc/version"); 
//   while(version_file.good())
//   {
//     std::string line;
//     while(std::getline(version_file, line))
//     {
//       std::cout<<line<<std::endl;
//       int version_quote  = line.find("version");
//       int version_bracket_quote = line.find("(");
//       std::cout<<version_quote<<std::endl<<version_bracket_quote<<std::endl;
//       std::string version_name = line.substr(version_quote, version_bracket_quote - version_quote);
//      std::cout<<version_name<<std::endl;
//     }
//   }
// }
    // std::getline(version_file, line);
    // std::cout<<line<<std::endl;
    // int version_quote  = line.find("version");
    // int version_bracket_quote = line.find("(");
    // std::cout<<version_quote<<std::endl<<version_bracket_quote<<std::endl;
    // std::string version_name = line.substr(version_quote, version_bracket_quote - version_quote);
    // std::cout<<version_name<<std::endl;

    // if(line.find("PRETTY") != std::string::npos)
    // {
    //   if(line.find("\"") != std::string::npos)
    //   {
    //     int first_quote = line.find("\"");
    //     int second_quote = line.find_last_of("\"");
    //     std::cout<<first_quote<<std::endl<<second_quote<<std::endl;
    //     std::string version_num= line.substr(first_quote+1,second_quote - first_quote - 1);
    //     std::cout<<version_num<<std::endl;
    //   }
    // }
  //}
  //return 0;
//}