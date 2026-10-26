int __thiscall sub_497750(void *this, int a2)
{
  int v3; // esi
  char *v4; // eax
  _BYTE v6[24]; // [esp+8h] [ebp-18h] BYREF

  PassthroughWrapper(v6);
  sub_4998E0(this);
  v3 = FieldAccessor(v6);
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = *(char **)(v3 + 52);
      if ( !v4 )
        v4 = byte_5EA438;
      if ( !sub_588410(v4, a2) )
        break;
      sub_499910(v6);
      v3 = FieldAccessor(v6);
      if ( !v3 )
        goto LABEL_6;
    }
    EmptyStub_0170(v6);
    return v3;
  }
  else
  {
LABEL_6:
    EmptyStub_0170(v6);
    return 0;
  }
}
