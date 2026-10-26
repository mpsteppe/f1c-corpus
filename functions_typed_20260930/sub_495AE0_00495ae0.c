int __thiscall sub_495AE0(_DWORD *this)
{
  int result; // eax
  _DWORD *v2; // esi
  int v3; // eax

  result = this[5];
  if ( result )
  {
    if ( *(_DWORD *)(result + 100) )
    {
      v2 = (_DWORD *)this[6];
      v3 = v2[26];
      this[6] = v3;
      *(_DWORD *)(v3 + 100) = 0;
      result = GuardedSubRectangleRenderDispatch(v2[1], v2[2], v2[3], v2[4]);
      v2[25] = 0;
      v2[26] = 0;
    }
  }
  return result;
}

