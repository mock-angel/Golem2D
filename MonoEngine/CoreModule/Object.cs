

namespace GolemEngine.CoreModule{

    class Object{
        public string name = null;
        public int ID = 0;

        public int GetInstanceID(){
            return 0; //TODO:Return ID instead;
        }

        public override string ToString()  {
            return name;
        }
        
        public static bool operator==(Object obj1, Object obj2){
            return ReferenceEquals(obj1, obj2);
        } 

        public static bool operator!=(Object obj1, Object obj2){
            return !ReferenceEquals(obj1, obj2);
        }

        public override bool Equals(object obj)
        {
            if (obj == null) return false;

            if (!(obj is Object)) return false;
            
            return this == (Object)obj;
        }

        public override int GetHashCode()
        {
            return name.GetHashCode() ^ ID.GetHashCode();
        }
    }


}