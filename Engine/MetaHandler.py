"""Test class to see if this method actally works."""

class MetaHandler:
    def __init__(self):
        self.meta_meta = {
            "GUID": None
            "Name": ""
        }
    
    
    def feed(self, data):
        for key in data:
            if key in self.meta_meta: self.meta_meta[key] = data[key]
        
    def apply_feed(self):
        """DO something to apply the setting."""
        pass
