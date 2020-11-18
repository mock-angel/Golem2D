using System;

namespace GolemEngine.CoreModule{
    public interface IComponent{
        
    }

    public class Component : IComponent{
        /*Returns the game object this component is attatched to.
        A component is always attatched to a gameObject.*/
        public GameObject gameObject {private set; get;}

        public Transform transform {private set; get;}


    }
}