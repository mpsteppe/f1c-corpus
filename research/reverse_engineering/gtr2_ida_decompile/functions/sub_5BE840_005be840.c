void __thiscall sub_5BE840(void *this, char a2)
{
  int v3; // edi
  int v4; // ebp
  int v5; // [esp+0h] [ebp-8h]

  v3 = 0;
  if ( *(int *)this > 0 )
  {
    v4 = 0;
    do
    {
      sub_5BE060();
      ++v3;
      v4 += 20;
    }
    while ( v3 < *(_DWORD *)this );
  }
  *(_DWORD *)this = 0;
  if ( a2 )
  {
    *((_DWORD *)this + 1) = 0;
    sub_4F14D0(v5);
    sub_5A8D10(*((void **)this + 2));
    *((_DWORD *)this + 2) = 0;
  }
}
