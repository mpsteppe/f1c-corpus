int __updatetlocinfo_lk()
{
  int v0; // esi
  _DWORD *v1; // ecx
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD **v6; // eax

  v0 = _getptd();
  v1 = *(_DWORD **)(v0 + 100);
  if ( v1 != off_91290C )
  {
    if ( v1 )
    {
      v2 = (_DWORD *)v1[11];
      --*v1;
      if ( v2 )
        --*v2;
      v3 = (_DWORD *)v1[13];
      if ( v3 )
        --*v3;
      v4 = (_DWORD *)v1[12];
      if ( v4 )
        --*v4;
      v5 = (_DWORD *)v1[16];
      if ( v5 )
        --*v5;
      --*(_DWORD *)(v1[19] + 180);
    }
    *(_DWORD *)(v0 + 100) = off_91290C;
    ++*(_DWORD *)off_91290C;
    v6 = (_DWORD **)off_91290C;
    if ( *((_DWORD *)off_91290C + 11) )
    {
      ++**((_DWORD **)off_91290C + 11);
      v6 = (_DWORD **)off_91290C;
    }
    if ( v6[13] )
    {
      ++*v6[13];
      v6 = (_DWORD **)off_91290C;
    }
    if ( v6[12] )
    {
      ++*v6[12];
      v6 = (_DWORD **)off_91290C;
    }
    if ( v6[16] )
    {
      ++*v6[16];
      v6 = (_DWORD **)off_91290C;
    }
    ++v6[19][45];
    if ( v1 && !*v1 && v1 != (_DWORD *)&unk_9128B8 )
      __freetlocinfo(v1);
  }
  return *(_DWORD *)(v0 + 100);
}
