// f1c  0x0040c070  size=183
int __thiscall sub_40C070(int this)
{
  int v2; // edi
  double v3; // st7
  int v4; // ebx
  int v5; // edi

  v2 = 0;
  if ( !*(_BYTE *)(this + 36) )
  {
    v3 = *(float *)(this + 60) - sub_40C780(this);
    *(float *)(this + 60) = v3;
    if ( v3 <= 0.0 )
    {
      v4 = sub_40CD60(this);
      switch ( sub_5884ED() % 4 )
      {
        case 0:
          v5 = 0;
          break;
        case 1:
          v5 = 3;
          break;
        case 2:
          v5 = 4;
          break;
        default:
          v5 = 5;
          break;
      }
      sub_40CDE0(v5, 1);
      if ( v5 != v4 )
        sub_40CDE0(v5, 1);
      if ( !(sub_5884ED() % 3) )
        sub_40D290(1);
      v2 = 1;
      sub_40D360(*(_DWORD *)(this + 48), *(_DWORD *)(this + 52));
    }
  }
  return v2;
}
