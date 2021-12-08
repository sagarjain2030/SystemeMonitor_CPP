#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include <iostream>
#include <fstream>
#include<algorithm>
#include <cstring>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"


using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_; }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() 
{
  return LinuxParser::Kernel(); 
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() 
{
  std::ifstream version_file("/proc/meminfo");
  float totalMemory = 0, freeMemory = 0;
  while(version_file.good())
  {
    std::string line;
    while(std::getline(version_file, line))
    {
      if(line.find("MemTotal") == 0 || line.find("MemFree") == 0)
      {
        int colon_quote = line.find(":");
        int kb_quote = line.find("kB");
        std::string memString = line.substr(colon_quote + 1,kb_quote - colon_quote - 1);
        memString.erase(remove_if(memString.begin(), memString.end(), isspace), memString.end());
        
        char * cstr = new char [memString.length()+1];
        std::strcpy (cstr, memString.c_str());
        
        if(totalMemory < 1.0)
          totalMemory = atof(cstr);
        else
          freeMemory = atof(cstr);
      }
    }
  }

  return ((totalMemory - freeMemory)/totalMemory) * 100.0;
}

// TODO: Return the operating system name
std::string System::OperatingSystem() 
{
  return LinuxParser::OperatingSystem();
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() 
{ 
    std::ifstream data_file("/proc/stat");
  double running_process;
  while(data_file.good())
  {
    std::string line;
    while(std::getline(data_file, line))
     {
       if(line.find("procs_running") == 0)
       {
         std::string running_process_String = line.substr(line.find(" ") + 1, line.length() - line.find(" "));
         running_process_String.erase(remove_if(running_process_String.begin(), running_process_String.end(), isspace), running_process_String.end());
         char* run_process_string = new char[running_process_String.length()+1];
         std::strcpy (run_process_string, running_process_String.c_str());
         running_process = atof(run_process_string); 
       }
     }
  }
  
  return running_process;
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() 
{ 
  std::ifstream data_file("/proc/stat");
  double total_process;
  while(data_file.good())
  {
    std::string line;
     while(std::getline(data_file, line))
     {
       if(line.find("processes") == 0)
       {
         std::string process_String = line.substr(line.find(" ") + 1, line.length() - line.find(" "));
         process_String.erase(remove_if(process_String.begin(), process_String.end(), isspace), process_String.end());
         char* tot_process_string = new char[process_String.length()+1];
         std::strcpy (tot_process_string, process_String.c_str());
         total_process = atof(tot_process_string); 
       }
     }
  }
  
  return total_process;
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() 
{ 
   std::ifstream data_file("/proc/uptime");
   double system_uptime;
   while(data_file.good())
   {
     std::string line;
      while(std::getline(data_file, line))
       {
        std::string uptime_string = line.substr(0, line.find(" "));
        uptime_string.erase(remove_if(uptime_string.begin(), uptime_string.end(), isspace), uptime_string.end());
        
        char* uptime_string_char = new char[uptime_string.length()+1];
        std::strcpy (uptime_string_char, uptime_string.c_str());
        system_uptime = atof(uptime_string_char);
      }
   }

   return system_uptime; 
}