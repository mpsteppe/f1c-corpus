int __stdcall sub_4B39B0(char *Buffer, int a2)
{
  char *v2; // ebp
  int v3; // eax
  int v4; // edi
  const char *v5; // esi
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = strcpy(Buffer, asc_609460);
  if ( *(_DWORD *)(dword_75AAC4 + 20892) )
    return 0;
  v3 = *(_DWORD *)(dword_75AAC4 + 21016);
  if ( !v3 || *(_DWORD *)(v3 + 20892) || sub_4B2C70(dword_75AAC4, v3, (float *)&Buffer, &v7) )
    return 0;
  v4 = v7;
  if ( v7 <= 0 )
  {
    *(float *)&Buffer = fabs(*(float *)&Buffer);
    sub_4B2BD0(*(float *)&Buffer, &v7, (float *)&Buffer);
    sprintf(v2, "+%.2d:%06.3f", v7, *(float *)&Buffer);
    return 0;
  }
  v5 = off_609480;
  if ( v7 != 1 )
    v5 = aLaps_0;
  if ( sub_41F230(dword_62A170, v5, Destination) )
  {
    if ( v5 )
    {
      strncpy(Destination, v5, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  sprintf(v2, " +%d %s", v4, Destination);
  return 0;
}
