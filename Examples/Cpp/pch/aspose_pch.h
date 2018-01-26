#pragma once

#include <cstdint>

#include <system/array.h>
#include <system/bit_converter.h>
#include <system/collections/icollection.h>
#include <system/collections/ienumerable.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ilist.h>
#include <system/collections/list.h>
#include <system/console.h>
#include <system/convert.h>
#include <system/date_time.h>
#include <system/details/dispose_guard.h>
#include <system/enum_helpers.h>
#include <system/environment.h>
#include <system/exceptions.h>
#include <system/guid.h>
#include <system/io/directory.h>
#include <system/io/file.h>
#include <system/io/file_access.h>
#include <system/io/file_mode.h>
#include <system/io/file_stream.h>
#include <system/io/memory_stream.h>
#include <system/io/path.h>
#include <system/io/seekorigin.h>
#include <system/io/stream.h>
#include <system/nullable.h>
#include <system/object.h>
#include <system/object_ext.h>
#include <system/shared_ptr.h>
#include <system/special_casts.h>
#include <system/string.h>
#include <system/string_comparison.h>
#include <system/text/encoding.h>
#include <system/timespan.h>
#include <system/timezone.h>
#include <system/timezone_info.h>

#include <AntiSpam/SpamAnalyzer.h>
#include <Formats/Appointments/Appointment.h>
#include <Formats/Appointments/AppointmentMethodType.h>
#include <Formats/Appointments/AppointmentSaveFormat.h>
#include <Formats/Mhtml/MhtFormatOptions.h>
#include <Formats/Outlook/IMapiMessageItem.h>
#include <Formats/Outlook/Mapi/BodyContentType.h>
#include <Formats/Outlook/Mapi/ContactSaveFormat.h>
#include <Formats/Outlook/Mapi/FollowUpManager.h>
#include <Formats/Outlook/Mapi/FollowUpOptions.h>
#include <Formats/Outlook/Mapi/MapiAttachment.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <Formats/Outlook/Mapi/MapiCalendar.h>
#include <Formats/Outlook/Mapi/MapiCalendarDailyRecurrencePattern.h>
#include <Formats/Outlook/Mapi/MapiCalendarDayOfWeek.h>
#include <Formats/Outlook/Mapi/MapiCalendarEventRecurrence.h>
#include <Formats/Outlook/Mapi/MapiCalendarMonthlyRecurrencePattern.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrenceEndType.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePattern.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePatternFactory.h>
#include <Formats/Outlook/Mapi/MapiCalendarRecurrencePatternType.h>
#include <Formats/Outlook/Mapi/MapiCalendarTimeZone.h>
#include <Formats/Outlook/Mapi/MapiCalendarWeeklyRecurrencePattern.h>
#include <Formats/Outlook/Mapi/MapiContact.h>
#include <Formats/Outlook/Mapi/MapiContactElectronicAddress.h>
#include <Formats/Outlook/Mapi/MapiContactElectronicAddressPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactGender.h>
#include <Formats/Outlook/Mapi/MapiContactNamePropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactOtherPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactPersonalInfoPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactPhoto.h>
#include <Formats/Outlook/Mapi/MapiContactPhotoImageFormat.h>
#include <Formats/Outlook/Mapi/MapiContactPhysicalAddress.h>
#include <Formats/Outlook/Mapi/MapiContactPhysicalAddressPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactProfessionalPropertySet.h>
#include <Formats/Outlook/Mapi/MapiContactTelephonePropertySet.h>
#include <Formats/Outlook/Mapi/MapiConversionOptions.h>
#include <Formats/Outlook/Mapi/MapiDistributionList.h>
#include <Formats/Outlook/Mapi/MapiDistributionListEntryIdType.h>
#include <Formats/Outlook/Mapi/MapiDistributionListMember.h>
#include <Formats/Outlook/Mapi/MapiDistributionListMemberCollection.h>
#include <Formats/Outlook/Mapi/MapiJournal.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <Formats/Outlook/Mapi/MapiMessageFlags.h>
#include <Formats/Outlook/Mapi/MapiMessageItemBase.h>
#include <Formats/Outlook/Mapi/MapiNamedProperty.h>
#include <Formats/Outlook/Mapi/MapiNote.h>
#include <Formats/Outlook/Mapi/MapiObjectProperty.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiPropertyTag.h>
#include <Formats/Outlook/Mapi/MapiRecipient.h>
#include <Formats/Outlook/Mapi/MapiRecipientCollection.h>
#include <Formats/Outlook/Mapi/MapiRecipientTrackStatus.h>
#include <Formats/Outlook/Mapi/MapiRecipientType.h>
#include <Formats/Outlook/Mapi/MapiTask.h>
#include <Formats/Outlook/Mapi/MapiTaskHistory.h>
#include <Formats/Outlook/Mapi/MapiTaskOwnership.h>
#include <Formats/Outlook/Mapi/MapiTaskState.h>
#include <Formats/Outlook/Mapi/MapiTaskStatus.h>
#include <Formats/Outlook/Mapi/MapiTaskUsers.h>
#include <Formats/Outlook/Mapi/NoteColor.h>
#include <Formats/Outlook/Mapi/NoteSaveFormat.h>
#include <Formats/Outlook/Mapi/OutlookMessageFormat.h>
#include <Formats/Outlook/Mapi/TaskSaveFormat.h>
#include <Formats/Outlook/Pst/FileFormat.h>
#include <Formats/Outlook/Pst/Messaging/Enums/FolderKind.h>
#include <Formats/Outlook/Pst/Messaging/Enums/MapiSensitivity.h>
#include <Formats/Outlook/Pst/Messaging/Enums/StandardIpmFolder.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/ItemMovedEventArgs.h>
#include <Formats/Outlook/Pst/Messaging/MessageAddedEventArgs.h>
#include <Formats/Outlook/Pst/Messaging/MessageAddedEventHandler.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfo.h>
#include <Formats/Outlook/Pst/Messaging/MessageInfoCollection.h>
#include <Formats/Outlook/Pst/Messaging/MessageStore.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/StorageProcessedEventArgs.h>
#include <Formats/VCard/VCardContact.h>
#include <Mail/Bounce/BounceResult.h>
#include <Mail/Bounce/DSNAction.h>
#include <Mail/MailAddress.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailMessage/FileCompatibilityMode.h>
#include <Mail/MailMessage/LoadOptions/EmlLoadOptions.h>
#include <Mail/MailMessage/LoadOptions/HtmlLoadOptions.h>
#include <Mail/MailMessage/LoadOptions/MhtmlLoadOptions.h>
#include <Mail/MailMessage/LoadOptions/MsgLoadOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/SaveOptions/EmlSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MhtSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/Mime/ContentType.h>
#include <Mail/Mime/HeaderCollection.h>
#include <Mail/Mime/MediaTypeNames.h>
#include <Mail/MimeParts/AlternateView.h>
#include <Mail/MimeParts/AlternateViewCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/LinkedResource.h>
#include <Mail/MimeParts/LinkedResourceCollection.h>
#include <Mail/TemplateMerge/MailMessageSaveType.h>
