int __thiscall sub_60A820(_DWORD *this, int *a2)
{
  int result; // eax
  int v4; // ebx
  int v5; // eax

  result = this[52];
  if ( a2 != (int *)result )
  {
    if ( a2 )
    {
      v4 = *(_DWORD *)dword_FB40C8;
      v5 = sub_5E7150(a2, 8);
      (*(void (__stdcall **)(int, _DWORD, int))(v4 + 260))(dword_FB40C8, this[51], v5);
      result = this[51];
      a2[28] = result;
      this[52] = a2;
    }
    else
    {
      result = (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB40C8 + 260))(dword_FB40C8, this[51], 0);
      this[52] = 0;
    }
  }
  return result;
}
