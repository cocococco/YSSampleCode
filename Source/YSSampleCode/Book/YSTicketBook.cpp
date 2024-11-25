// Fill out your copyright notice in the Description page of Project Settings.


#include "YSTicketBook.h"
#include "YSSampleCode/DataTypes/YSCommonDataTypes.h"

bool FYSTicketGroupKey::IsValid() const
{
	if (ContentType == EYSTicketContentType::None || ContentId == INVALID_ID || TicketType == EYSTicketType::None)
	{
		return false;
	}

	return true;
}

bool FYSTicketGroupKey::operator==(const FYSTicketGroupKey& InOther) const
{
	return (ContentType == InOther.ContentType && ContentId == InOther.ContentId && TicketType == InOther.TicketType);
}

bool FYSTicketGroupKey::operator!=(const FYSTicketGroupKey& InOther) const
{
	return !(*this == InOther);
}
