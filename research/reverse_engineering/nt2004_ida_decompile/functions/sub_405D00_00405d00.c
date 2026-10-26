int __stdcall sub_405D00(char *FileName, int *a2)
{
  int v2; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-4h] [ebp-8h]

  sub_405C90();
  v2 = sub_408CF0(FileName);
  if ( v2 == -1 )
  {
    if ( FileName
      && strlen(FileName) >= 5
      && sub_579060(FileName, asc_5FB910)
      && (v6 = atoi(FileName + 4), sub_405C90(), (v4 = sub_408C20(0, v6)) != 0) )
    {
      *a2 = *(_DWORD *)(v4 + 16);
      return 1;
    }
    else
    {
      v5 = _open(FileName, 0x8000, 256);
      if ( v5 == -1 )
      {
        return 0;
      }
      else
      {
        *a2 = v5;
        return 1;
      }
    }
  }
  else
  {
    *a2 = v2;
    return 1;
  }
}
