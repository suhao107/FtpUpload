========================================================================
    ACTIVEX 控件 DLL : FtpUpLoadFiles 项目概述
========================================================================

控件向导已为 FtpUpLoadFiles ActiveX 控件 DLL 创建此项目，其中包含一个控件。

此主干项目不仅演示了编写 ActiveX 控件的基本方法，而且还可以作为编写控件特定功能的起点。

本文件概要介绍组成 FtpUpLoadFiles ActiveX 控件 DLL 的每个文件的内容。

FtpUpLoadFiles.vcxproj
    这是使用应用程序向导生成的 VC++ 项目的主项目文件，其中包含生成该文件的 Visual C++ 的版本信息，以及有关使用应用程序向导选择的平台、配置和项目功能的信息。

FtpUpLoadFiles.vcxproj.filters
    这是使用“应用程序向导”生成的 VC++ 项目筛选器文件。它包含有关项目文件与筛选器之间的关联信息。在 IDE 中，通过这种关联，在特定节点下以分组形式显示具有相似扩展名的文件。例如，“.cpp”文件与“源文件”筛选器关联。

FtpUpLoadFiles.h
    这是 ActiveX 控件 DLL 的主包含文件。其中包括其他项目特定的文件，如 resource.h。

FtpUpLoadFiles.cpp
    这是包含 DLL 初始化、终止和其他簿记的代码的主源文件。

FtpUpLoadFiles.rc
    这是项目使用的 Microsoft Windows 资源的清单。此文件可以直接用 Visual C++ 资源编辑器进行编辑。

FtpUpLoadFiles.def
    此文件包含关于在 Microsoft Windows 上运行所必需的 ActiveX 控件 DLL 的有关信息。

FtpUpLoadFiles.idl
    此文件包含控件类型库的对象描述语言源代码。

FtpUpLoadFiles.ico
    此文件包含将出现在“关于”框中的图标。此图标包括在主资源文件 FtpUpLoadFiles.rc 中。

/////////////////////////////////////////////////////////////////////////////
CFtpUpLoadFilesCtrl control:

FtpUpLoadFilesCtrl.h
    此文件包含 CFtpUpLoadFilesCtrl C++ 类的声明。

FtpUpLoadFilesCtrl.cpp
    此文件包含 CFtpUpLoadFilesCtrl C++ 类的实现。

FtpUpLoadFilesPropPage.h
    此文件包含 CFtpUpLoadFilesPropPage C++ 类的声明。

FtpUpLoadFilesPropPage.cpp
    此文件包含 CFtpUpLoadFilesPropPage C++ 类的实现。

CFtpUpLoadFilesCtrl.bmp
    此文件包含一个位图，当 CFtpUpLoadFilesCtrl 控件出现在工具面板上时，容器将使用此位图来表示该控件。此位图包含在主资源文件 FtpUpLoadFiles.rc 中。

/////////////////////////////////////////////////////////////////////////////
其他标准文件:

stdafx.h, stdafx.cpp
    这些文件用于生成名为 FtpUpLoadFiles.pch 的预编译头 (PCH) 文件和名为 stdafx.obj 的预编译类型 (PCT) 文件。

resource.h
    这是标准头文件，可用于定义新的资源 ID。Visual C++ 资源编辑器读取并更新此文件。

/////////////////////////////////////////////////////////////////////////////
其他注释:

控件向导使用“TODO:”来指示应添加或自定义的源代码部分。

/////////////////////////////////////////////////////////////////////////////
