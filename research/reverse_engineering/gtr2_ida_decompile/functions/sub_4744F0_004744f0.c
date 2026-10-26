int __thiscall sub_4744F0(int *this)
{
  int result; // eax
  int v3; // ecx
  char *v4; // eax

  if ( *(_DWORD *)(*this + 113328) == 4 && *(_DWORD *)(*this + 113316) && sub_59B670(*(_DWORD *)(*this + 113316)) == 3 )
    *(_DWORD *)(*this + 113328) = 3;
  result = *this;
  v3 = *(_DWORD *)(*this + 113328);
  if ( v3 > 0 && v3 <= 3 )
  {
    *(float *)(result + 2124) = *(float *)(result + 2124) - dbl_FB1D08;
    result = sub_59B670(*(_DWORD *)(*this + 113316));
    if ( !result )
    {
      result = *(unsigned __int8 *)(*this + 1192);
      if ( !(_BYTE)result )
      {
        v4 = sub_41D840(&byte_91CC38, "Connection lost");
        sub_4730C0((int **)&dword_B6CB98, v4, 3, (int)&byte_1020304, 1084227584);
        result = *this;
        *(_BYTE *)(*this + 1192) = 1;
      }
    }
  }
  return result;
}
