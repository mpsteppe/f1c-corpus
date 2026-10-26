char __thiscall sub_5855E0(int this)
{
  signed int v2; // esi
  char result; // al
  void *v4; // eax
  DWORD v5; // eax
  DWORD v6; // eax
  void *v7; // eax
  char v8; // [esp+Bh] [ebp-5h]
  _BYTE *v9; // [esp+Ch] [ebp-4h]

  v2 = 0;
  result = 1;
  v8 = 1;
  if ( *(_DWORD *)(this + 4) )
  {
    v4 = *(void **)(this + 32);
    if ( v4 && ((v5 = WaitForSingleObject(v4, *(_DWORD *)(this + 36))) == 0 || v5 == 128) )
      v9 = (_BYTE *)(this + 28);
    else
      v9 = 0;
    if ( !*v9 )
    {
      while ( 1 )
      {
        ++v2;
        v6 = SuspendThread(*(HANDLE *)(this + 4));
        if ( v6 != -1 )
        {
          if ( v6 )
            break;
        }
        Sleep(v2);
        if ( v2 >= 50 )
        {
          v8 = 0;
          goto LABEL_12;
        }
      }
      *v9 = 1;
    }
LABEL_12:
    v7 = *(void **)(this + 32);
    if ( v7 )
      ReleaseMutex(v7);
    return v8;
  }
  return result;
}
