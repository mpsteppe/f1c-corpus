int __thiscall sub_4C28D0(_DWORD *this, int a2)
{
  int v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // eax

  if ( !LinkedListSearchByName(this, a2) )
  {
    SceneDataParser(a2);
    v3 = dword_8AC490 + 396 * dword_8AC48C;
    if ( v3 )
    {
      v4 = (_DWORD *)OperatorNewNhMallocWrapper(24);
      v5 = v4 ? AlternatingInit(v4) : 0;
      StringCopyWithBufferRealloc(v3 + 260);
      StringCopyWithBufferRealloc(v3 + 4);
      if ( v5 )
      {
        v6 = OperatorNewNhMallocWrapper(12);
        if ( v6 )
        {
          *(_DWORD *)v6 = v5;
          *(_DWORD *)(v6 + 4) = 0;
          *(_BYTE *)(v6 + 8) = 1;
        }
        else
        {
          v6 = 0;
        }
        if ( this[4] )
        {
          *(_DWORD *)(this[5] + 4) = v6;
        }
        else
        {
          this[4] = v6;
          this[6] = v6;
        }
        this[5] = v6;
        ++this[7];
      }
    }
  }
  return LinkedListSearchByName(this, a2);
}
