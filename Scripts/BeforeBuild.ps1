$ProgressPreference = 'SilentlyContinue'  # For Invoke-WebRequest
[Net.ServicePointManager]::SecurityProtocol = 'Tls, Tls11, Tls12'  # For Invoke-WebRequest
Invoke-WebRequest -Uri 'https://curl.haxx.se/ca/cacert.pem' -Out 'cacert.pem'
Copy-Item cacert.pem 'Combo\Debug\PCMan Combo\'
Copy-Item cacert.pem 'Combo\Release\PCMan Combo\'
Copy-Item cacert.pem 'Lite\Debug\PCMan\'
Copy-Item cacert.pem 'Lite\Release\PCMan\'

Invoke-WebRequest -Uri 'https://go.microsoft.com/fwlink/?LinkId=746571' -Out 'vc_redist.x86.exe'

Copy-Item 'OpenSourceLicenses.txt' 'Combo\Debug\PCMan Combo\'
Copy-Item 'OpenSourceLicenses.txt' 'Combo\Release\PCMan Combo\'
Copy-Item 'OpenSourceLicenses.txt' 'Lite\Debug\PCMan\'
Copy-Item 'OpenSourceLicenses.txt' 'Lite\Release\PCMan\'

Copy-Item 'C:\tools\vcpkg\installed\x86-windows\bin\zlib1.dll' 'Combo\Debug\PCMan Combo\'
Copy-Item 'C:\tools\vcpkg\installed\x86-windows\bin\zlib1.dll' 'Combo\Release\PCMan Combo\'
Copy-Item 'C:\tools\vcpkg\installed\x86-windows\bin\zlib1.dll' 'Lite\Debug\PCMan\'
Copy-Item 'C:\tools\vcpkg\installed\x86-windows\bin\zlib1.dll' 'Lite\Release\PCMan\'

md Release
& .\Version_PreBuildEvent_Combo.bat
& .\Version_PreBuildEvent_Lite.bat
