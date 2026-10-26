int __thiscall sub_5B8F70(int *this)
{
  int v2; // eax
  int v4; // eax
  int v5; // eax

  if ( this[1294] )
  {
    v2 = (*(int (__stdcall **)(int, void *, void *, int *, int))(*(_DWORD *)this[1112] + 300))(
           this[1112],
           &unk_61C3D4,
           &unk_61C3E8,
           &dword_7FEEB8,
           16);
    *this = v2;
    if ( v2 )
    {
      return -1;
    }
    else
    {
      v4 = (*(int (__stdcall **)(int, void *, void *, int *, int))(*(_DWORD *)this[1112] + 300))(
             this[1112],
             &unk_61CE10,
             &unk_61CE28,
             &dword_7FEEB0,
             16);
      *this = v4;
      if ( v4 )
      {
        return -1;
      }
      else
      {
        v5 = (*(int (__stdcall **)(int, void *, void *, int *, int))(*(_DWORD *)this[1112] + 300))(
               this[1112],
               &unk_61C258,
               &unk_61C270,
               &dword_7FEEB4,
               16);
        *this = v5;
        if ( v5 )
        {
          return -1;
        }
        else
        {
          *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1112] + 200))(this[1112], 153, 1);
          return 0;
        }
      }
    }
  }
  else
  {
    dword_7FEEB8 = 0;
    dword_7FEEB0 = 0;
    dword_7FEEB4 = 324;
    return 0;
  }
}
