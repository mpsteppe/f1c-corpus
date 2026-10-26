void **__userpurge sub_5A8920@<eax>(void **a1@<ecx>, int a2@<edi>, int a3, unsigned int a4)
{
  void *v6; // edi
  int v7; // [esp+0h] [ebp-8h]
  const void *v8; // [esp+4h] [ebp-4h]

  if ( a3 )
  {
    sub_4F14D0(a2);
    sub_5A8D10(a1[1]);
    a1[1] = 0;
    sub_5A8860(a1, a4, 0);
    v6 = a1[1];
    if ( v6 )
      qmemcpy(v6, v8, a4);
    return a1;
  }
  else
  {
    sub_4F14D0(v7);
    sub_5A8D10(a1[1]);
    a1[1] = 0;
    return a1;
  }
}
