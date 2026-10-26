void __thiscall sub_59D6A9(_DWORD *this, int a1)
{
  int v2; // ecx
  int v3; // eax

  if ( this )
  {
    v3 = this[2];
    if ( v3 )
    {
      v2 = a1;
      do
      {
        if ( v2 <= 0 )
          break;
        v3 = *(_DWORD *)(v3 + 4);
        --v2;
      }
      while ( v3 );
    }
  }
  nullsub_9(a1);
}
