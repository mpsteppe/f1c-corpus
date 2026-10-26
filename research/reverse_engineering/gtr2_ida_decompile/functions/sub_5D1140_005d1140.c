void __usercall sub_5D1140(_DWORD *a1@<ecx>, int a2@<edi>)
{
  _DWORD *v2; // esi
  int v3; // edi
  int v4; // ebx

  *a1 = &off_72B37C;
  v2 = a1 + 1;
  v3 = 0;
  if ( (int)a1[1] > 0 )
  {
    v4 = 0;
    do
    {
      (**(void (__thiscall ***)(int, _DWORD))(v4 + v2[2]))(v4 + v2[2], 0);
      ++v3;
      v4 += 16;
    }
    while ( v3 < *v2 );
  }
  sub_4F14D0(a2);
  sub_5A8D10((void *)v2[2]);
}
