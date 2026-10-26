int sub_58F6FE()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi

  if ( dword_8D3F3C )
  {
    v0 = sub_58AB58(1, 48);
    v1 = v0;
    if ( !v0 )
      return 1;
    if ( sub_58F7C9(v0) )
    {
      MultiFieldFree_f8eb(v1);
      sub_58AA6F(v1);
      return 1;
    }
    *v1 = *off_5E9AC0;
    v1[1] = off_5E9AC0[1];
    v1[2] = off_5E9AC0[2];
    off_5E9AC0 = (_UNKNOWN **)v1;
    MultiFieldFree_f8eb(dword_8D3F68);
    sub_58AA6F(dword_8D3F68);
    dword_8D3F68 = v1;
  }
  else
  {
    off_5E9A90 = *off_5E9AC0;
    off_5E9A94 = off_5E9AC0[1];
    off_5E9A98 = off_5E9AC0[2];
    off_5E9AC0 = &off_5E9A90;
    MultiFieldFree_f8eb(dword_8D3F68);
    sub_58AA6F(dword_8D3F68);
    dword_8D3F68 = 0;
  }
  return 0;
}
