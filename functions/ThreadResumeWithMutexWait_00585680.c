char __thiscall sub_585680(int this)
{
  void *v2; // eax
  int v3; // esi
  DWORD v4; // eax
  char *v5; // edi
  void *v6; // esi
  void *v7; // eax
  signed int v8; // esi
  DWORD v9; // eax
  char v11; // [esp+13h] [ebp-5h]
  int v12; // [esp+14h] [ebp-4h]
  _BYTE *v13; // [esp+14h] [ebp-4h]

  v2 = *(void **)(this + 212);
  v3 = this + 132;
  v11 = 1;
  if ( v2 && ((v4 = WaitForSingleObject(v2, *(_DWORD *)(this + 216))) == 0 || v4 == 128) )
    v5 = (char *)v3;
  else
    v5 = 0;
  *(float *)&v12 = FloatAdditionReturnsFUN00568d90Param1(v5);
  FloatSetWithTimingCall(v5, v12);
  v6 = *(void **)(v3 + 80);
  if ( v6 )
    ReleaseMutex(v6);
  if ( !*(_DWORD *)(this + 4) )
    return 1;
  v7 = *(void **)(this + 32);
  v8 = 0;
  if ( v7 && ((v9 = WaitForSingleObject(v7, *(_DWORD *)(this + 36))) == 0 || v9 == 128) )
    v13 = (_BYTE *)(this + 28);
  else
    v13 = 0;
  if ( *v13 )
  {
    while ( 1 )
    {
      ++v8;
      if ( ResumeThread(*(HANDLE *)(this + 4)) < 2 )
        break;
      Sleep(v8);
      if ( v8 >= 50 )
      {
        v11 = 0;
        goto LABEL_18;
      }
    }
    *v13 = 0;
  }
LABEL_18:
  if ( *(_DWORD *)(this + 32) )
    ReleaseMutex(*(HANDLE *)(this + 32));
  return v11;
}
