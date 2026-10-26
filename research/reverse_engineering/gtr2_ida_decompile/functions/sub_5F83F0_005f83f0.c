int __thiscall sub_5F83F0(_DWORD *this)
{
  int result; // eax
  _DWORD v2[4]; // [esp+0h] [ebp-10h] BYREF

  result = dword_FB27A4;
  if ( *(int *)(dword_FB27A4 + 4) >= 0 )
  {
    if ( this[84] == 3 )
    {
      v2[0] = 0;
      v2[1] = 0;
      v2[2] = 1;
      v2[3] = 0;
      (*(void (__stdcall **)(int, _DWORD, _DWORD *, int))(*(_DWORD *)dword_FB40C8 + 384))(dword_FB40C8, 0, v2, 1);
    }
    else
    {
      memset(&unk_FB3338, 0, 0x80u);
      memset(&unk_FB33F8, 0, 0x80u);
      (*(void (__stdcall **)(int, int, void *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 72, &unk_FB3338, 8);
      (*(void (__stdcall **)(int, int, void *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 84, &unk_FB33F8, 8);
    }
    result = dword_FB27A4;
    *(_DWORD *)(dword_FB27A4 + 4) |= 0x80000000;
  }
  return result;
}
