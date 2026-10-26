void __usercall sub_527C40(_DWORD *a1@<ecx>, int a2@<edi>)
{
  int **v2; // esi
  _BYTE *v3; // ecx
  int v4; // eax

  if ( *a1 == 2 )
  {
    v2 = (int **)(a1 + 2);
    v3 = (_BYTE *)a1[2];
    if ( !v3[2892961] )
    {
      v4 = sub_522B60(v3);
      if ( v4 != 3 )
      {
        sub_522C30(*v2, v4, 1);
        sub_527AF0((int *)v2, a2);
        return;
      }
      sub_540190(1065353216);
      sub_5239A0((int *)v2);
    }
    sub_527AF0((int *)v2, a2);
  }
}
