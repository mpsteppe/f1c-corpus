int __thiscall sub_50AFB0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  int result; // eax

  sub_50AEE0(this, (int)(this + 389));
  sub_50AEE0(this, (int)(this + 406));
  v2 = (int)(this + 102);
  v3 = 4;
  do
  {
    sub_50AEE0(this, v2 - 68);
    sub_50AEE0(this, v2);
    v2 += 304;
    --v3;
  }
  while ( v3 );
  v4 = (int)(this + 423);
  v5 = 12;
  do
  {
    result = sub_50AEE0(this, v4);
    v4 += 68;
    --v5;
  }
  while ( v5 );
  return result;
}
