int __thiscall sub_463BC0(int *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // edi
  int result; // eax
  int v8; // ecx
  bool v9; // zf
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  bool v14; // cc

  v2 = this[2];
  v3 = this[3];
  v4 = *this;
  this[4] = (v3 - v2) / 2;
  this[5] = (this[1] - v4) / 2;
  v5 = (Rect.bottom + Rect.top) / 2;
  v6 = (Rect.right + Rect.left) / 2;
  SetCursorPos(v6, v5);
  result = v6 - this[4];
  v8 = v5 - this[5];
  v9 = v6 == this[4];
  this[6] = 0;
  this[7] = 0;
  if ( !v9 || v8 )
  {
    v9 = *((_BYTE *)this + 192) == 0;
    this[7] = v8;
    this[6] = result;
    if ( v9 )
    {
      v11 = this[2];
      this[4] = v6;
      if ( v6 < v11 )
        this[4] = v11;
      v12 = this[3];
      if ( this[4] > v12 )
        this[4] = v12;
      v13 = *this;
      v14 = v5 < *this;
      this[5] = v5;
      if ( v14 )
        this[5] = v13;
      result = this[1];
      if ( this[5] > result )
        this[5] = result;
    }
    else
    {
      v10 = *this;
      this[4] = (this[2] + this[3] + 1) / 2;
      this[5] = (this[1] + v10 + 1) / 2;
      result = SetCursorPos((Rect.right + Rect.left) / 2, (Rect.bottom + Rect.top) / 2);
    }
    *((float *)this + 10) = (double)this[4] * *((float *)this + 8);
    *((float *)this + 11) = (double)this[5] * *((float *)this + 9);
  }
  return result;
}
