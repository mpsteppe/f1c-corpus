_DWORD *__thiscall sub_505640(void *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  result = 0;
  if ( !this )
  {
    v2 = operator new(0x1ECu);
    v3 = v2;
    if ( v2 )
    {
      *v2 = &off_5EA960;
      v2[1] = 0;
      *((_BYTE *)v2 + 8) = 0;
      v2[3] = 0;
      sub_4B5EB0(v2 + 4);
      sub_4B5EB0(v3 + 23);
      sub_4B5EB0(v3 + 42);
      sub_4B5EB0(v3 + 61);
      sub_4B5EB0(v3 + 80);
      sub_506720(v3 + 99);
      v3[109] = 0;
      v3[110] = -1;
      v3[111] = 0;
      v3[112] = -1;
      sub_506BA0(v3 + 99);
      sub_504470(v3 + 115);
      sub_504470(v3 + 119);
      *v3 = &off_5EA9E0;
      return v3;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
