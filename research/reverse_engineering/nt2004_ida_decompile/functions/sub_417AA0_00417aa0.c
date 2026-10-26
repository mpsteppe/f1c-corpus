int __thiscall sub_417AA0(float *this, float a2)
{
  int v3; // esi
  int result; // eax
  int i; // edi
  int v6; // edi
  bool v7; // cc
  int v8; // ecx
  int j; // edi
  int v10; // ecx

  if ( dword_7D5DA4 == 2 )
  {
    v3 = sub_42F2D0(&unk_62BF64);
    for ( result = sub_42F2C0(&unk_62BF64); !(_BYTE)result; result = sub_42F2C0(&unk_62BF64) )
    {
      sub_51CDC0(a2);
      sub_51B7F0((char *)&unk_62BFBC + 25304 * v3);
      v3 = sub_42F310(&unk_62BF64);
    }
  }
  else
  {
    for ( i = 0; i < *(_DWORD *)this; ++i )
      sub_416400(*(_DWORD **)(*((_DWORD *)this + 2) + 4 * i), a2);
    if ( dword_7D5DA4 == 1 && this[28] + 0.30000001 < a2 )
    {
      result = *(_DWORD *)this;
      v6 = 0;
      v7 = *(_DWORD *)this <= 0;
      this[28] = a2;
      if ( !v7 )
      {
        do
        {
          v8 = *(_DWORD *)(*((_DWORD *)this + 2) + 4 * v6);
          if ( *(_DWORD *)(v8 + 32) != 6 )
            sub_416750(v8);
          result = *(_DWORD *)this;
          ++v6;
        }
        while ( v6 < *(_DWORD *)this );
      }
    }
    else
    {
      result = *(_DWORD *)this;
      for ( j = 0; j < *(_DWORD *)this; ++j )
      {
        v10 = *(_DWORD *)(*((_DWORD *)this + 2) + 4 * j);
        if ( *(_DWORD *)(v10 + 32) != 6 && *(_DWORD *)(v10 + 12) != 1 )
          sub_416750(v10);
        result = *(_DWORD *)this;
      }
    }
  }
  return result;
}
