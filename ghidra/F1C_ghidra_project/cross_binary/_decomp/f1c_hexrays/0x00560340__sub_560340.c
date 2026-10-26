// f1c  0x00560340  size=208
int __thiscall sub_560340(int *this)
{
  int v2; // eax
  int v4; // eax
  int v5; // eax

  if ( this[1269] )
  {
    v2 = (*(int (__stdcall **)(int, void *, void *, int *, int))(*(_DWORD *)this[1088] + 300))(
           this[1088],
           &unk_5DC7A4,
           &unk_5DC7B8,
           &dword_8CEF7C,
           16);
    *this = v2;
    if ( v2 )
    {
      return -1;
    }
    else
    {
      v4 = (*(int (__stdcall **)(int, void *, void *, int *, int))(*(_DWORD *)this[1088] + 300))(
             this[1088],
             &unk_5DD1E0,
             &unk_5DD1F8,
             &dword_8CEF74,
             16);
      *this = v4;
      if ( v4 )
      {
        return -1;
      }
      else
      {
        v5 = (*(int (__stdcall **)(int, void *, void *, int *, int))(*(_DWORD *)this[1088] + 300))(
               this[1088],
               &unk_5DC628,
               &unk_5DC640,
               &dword_8CEF78,
               16);
        *this = v5;
        if ( v5 )
        {
          return -1;
        }
        else
        {
          *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 200))(this[1088], 153, 1);
          return 0;
        }
      }
    }
  }
  else
  {
    dword_8CEF7C = 0;
    dword_8CEF74 = 0;
    dword_8CEF78 = 324;
    return 0;
  }
}
