char __thiscall sub_479630(void *this)
{
  char result; // al
  int v3; // eax
  char v4; // al

  result = 0;
  if ( *(_BYTE *)(*(_DWORD *)this + 1415) )
  {
    v3 = dword_B7231C;
    *(_DWORD *)dword_B72314 = 5;
    if ( dword_B7231C > 5 || (v3 = dword_B72320, dword_B72320 < 5) )
      *(_DWORD *)dword_B72314 = v3;
    v4 = byte_B73392;
    byte_B73390 = 1;
    if ( (unsigned __int8)byte_B73392 > 1u || (v4 = byte_B73393) == 0 )
      byte_B73390 = v4;
    sub_59B690(*(_DWORD *)(*(_DWORD *)this + 113316));
    if ( *(_DWORD *)this + 1584 + strlen((const char *)(*(_DWORD *)this + 1584)) + 1 == *(_DWORD *)this + 1585
      || *(_DWORD *)this == -1584 )
    {
      sub_4E1810("MULTIPLAYER_CREATEGAME", 0);
      return 1;
    }
    else
    {
      sub_4E1810("CIRCUIT_SELECT", 0);
      return 1;
    }
  }
  return result;
}
