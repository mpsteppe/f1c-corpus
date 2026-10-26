int __thiscall sub_4BC060(int this, char a2)
{
  int v3; // esi
  int result; // eax
  int v5; // [esp+0h] [ebp-10h]

  if ( dword_7C56A4 == 7 )
  {
    v3 = dword_8AAE64;
    if ( dword_83EE60 < 1023 )
    {
      ++dword_83EE60;
      dword_8AAE64 += 432;
    }
    *(float *)&v5 = dbl_8AFEA0;
    if ( a2 )
    {
      result = ProgressBarEventEncode((_DWORD *)v3, 4, 26, 1, *(_DWORD *)(this + 4), v5, 0);
      *(_BYTE *)(v3 + 8) = *(_BYTE *)(this + 52);
    }
    else
    {
      return ProgressBarEventEncode((_DWORD *)v3, 4, 27, 0, *(_DWORD *)(this + 4), v5, 0);
    }
  }
  return result;
}

