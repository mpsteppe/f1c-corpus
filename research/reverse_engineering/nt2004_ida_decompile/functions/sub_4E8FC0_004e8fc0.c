char __stdcall sub_4E8FC0(char *Source)
{
  int v1; // eax
  const char *v2; // eax
  bool v3; // zf
  char result; // al
  char Destination[61]; // [esp+4h] [ebp-40h] BYREF
  __int16 v6; // [esp+41h] [ebp-3h]
  char v7; // [esp+43h] [ebp-1h]

  if ( !Source )
    return 0;
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v6 = 0;
  v7 = 0;
  strncpy(Destination, Source, 0x3Fu);
  v7 = 0;
  if ( !sub_57AE50(aSeasonraces) )
    return 0;
  if ( !sub_57A720(Destination) )
    return 0;
  v1 = sub_57A720(aTrackType);
  if ( !v1 )
    return 0;
  v2 = (const char *)sub_57A6D0(v1);
  v3 = _strcmpi(v2, aRoadCourse_0) == 0;
  result = 1;
  if ( !v3 )
    return 0;
  return result;
}
