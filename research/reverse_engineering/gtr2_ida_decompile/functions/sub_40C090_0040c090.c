int __thiscall sub_40C090(int *this)
{
  int result; // eax
  int *v3; // eax
  int v4; // ecx
  int *v5; // eax

  result = this[34];
  if ( result )
  {
    v3 = (int *)this[2];
    this[4] = (int)v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        do
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 24))(v4);
          v5 = (int *)this[2];
          this[4] = (int)v5;
          if ( !v5 )
            break;
          v4 = *v5;
        }
        while ( *v5 );
      }
    }
    sub_59EAD0(this + 6);
    sub_409FB0(this + 10);
    sub_40BF70(this + 14);
    (*(void (__thiscall **)(int *, _DWORD))(*this + 52))(this, 0);
    return off_16C9794();
  }
  return result;
}
