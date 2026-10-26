char *__stdcall sub_5681F0(int a1)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)AudioChannelStop(a1);
  if ( v1 )
    return DataEntryAccessor(v1);
  else
    return 0;
}

