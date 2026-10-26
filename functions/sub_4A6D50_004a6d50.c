void __thiscall sub_4A6D50(_DWORD *this)
{
  int v2; // ebp
  int v3; // edi
  _DWORD *v4; // ebx

  if ( dword_7C56A4 == 7 )
  {
    if ( *(_DWORD *)(*this + 16448) )
    {
      v2 = *(_DWORD *)(*this + 16444) + 1;
      v3 = 0;
      if ( (int)this[88] > 0 )
      {
        v4 = this + 89;
        do
        {
          if ( *v4 == v2 )
            StateChangeNotify((int)this, 1);
          ++v3;
          v4 += 2;
        }
        while ( v3 < this[88] );
      }
    }
  }
}
