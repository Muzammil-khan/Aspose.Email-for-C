﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Formats/Outlook/Mapi/OutlookMessageFormat.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiConversionOptions.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Outlook;


void ConvertMIMEMessagesFromMSGToEML()
{
    // ExStart:ConvertMIMEMessagesFromMSGToEML
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::SharedPtr<MailMessage> msg = MailMessage::Load(dataDir + L"message.eml");
    System::SharedPtr<MapiMessage> mapi = MapiMessage::FromMailMessage(msg, System::MakeObject<MapiConversionOptions>(Aspose::Email::Outlook::OutlookMessageFormat::Unicode));
    // Save File to disk
    mapi->Save(dataDir + L"ConvertMIMEMessagesFromMSGToEML_out.msg");
    // ExEnd:ConvertMIMEMessagesFromMSGToEML
}







