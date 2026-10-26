char __thiscall sub_5A4030(int this)
{
  void *v2; // eax
  int v3; // esi
  DWORD v4; // eax
  float *v5; // edi
  void *v6; // esi
  void *v7; // eax
  int v8; // ebp
  DWORD v9; // eax
  signed int v10; // esi
  char v11; // bl
  _BYTE *v13; // [esp+14h] [ebp-4h]

  v2 = *(void **)(this + 224);
  v3 = this + 136;
  if ( v2 && ((v4 = WaitForSingleObject(v2, *(_DWORD *)(this + 228))) == 0 || v4 == 128) )
    v5 = (float *)v3;
  else
    v5 = 0;
  *v5 = sub_617F80(v5 + 2) + *v5;
  sub_617E70(v5 + 2);
  v6 = *(void **)(v3 + 88);
  if ( v6 )
    ReleaseMutex(v6);
  if ( !*(_DWORD *)(this + 8) )
    return 1;
  v7 = *(void **)(this + 36);
  v8 = this + 32;
  if ( v7 && ((v9 = WaitForSingleObject(v7, *(_DWORD *)(this + 40))) == 0 || v9 == 128) )
    v13 = (_BYTE *)(this + 32);
  else
    v13 = 0;
  if ( *v13 )
  {
    v10 = 0;
    while ( 1 )
    {
      ++v10;
      if ( ResumeThread(*(HANDLE *)(this + 8)) < 2 )
        break;
      Sleep(v10);
      if ( v10 >= 50 )
      {
        v11 = 0;
        goto LABEL_21;
      }
    }
    *v13 = 0;
  }
  v11 = 1;
LABEL_21:
  if ( *(_DWORD *)(v8 + 4) )
    ReleaseMutex(*(HANDLE *)(v8 + 4));
  return v11;
}
