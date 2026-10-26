int __thiscall sub_57A730(ULONG_PTR *this, int a2)
{
  LinkedListWalkWithInputDispatch(a2);
  return QueueUserAPCAsyncProcedureCall(*this, 0);
}
