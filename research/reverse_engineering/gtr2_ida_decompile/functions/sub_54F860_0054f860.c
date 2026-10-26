int __thiscall sub_54F860(_DWORD *this)
{
  int v3; // esi
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h] BYREF

  sub_5DA960(&v5, 2048);
  sub_5DA960(&v6, 2048);
  if ( v5 >= 104 )
  {
    if ( v5 == 104 && *((_DWORD *)off_757C18 + 3705) == 1 )
    {
      if ( (unsigned __int8)sub_52B420() )
      {
        v3 = sub_416730(&dword_82F4A0);
        sub_51B2A0((_DWORD *)v3, 4, 8, 8, v4, 0, 0);
        *(_DWORD *)(v3 + 8) = 0;
        *(_WORD *)(v3 + 12) = v5;
        *(_WORD *)(v3 + 14) = -1;
      }
    }
    sub_5ED990(this[5]);
    return 0;
  }
  else
  {
    sub_52E2D0((int)&unk_924FE8 + 22616 * v5, this);
    sub_427C40((int)&unk_9204A0 + 22616 * v5, v6 + 1, 0);
    sub_5ED990(this[5]);
    return 0;
  }
}
